#include "Shape.h"
#include <iostream>

#define EIGEN_DONT_ALIGN_STATICALLY
#include <Eigen/Dense>

#include "GLSL.h"
#include "Program.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

using namespace Eigen;
using namespace std;

Shape::Shape() :
	eleBufID(0),
	posBufID(0),
	norBufID(0),
	texBufID(0), 
    vaoID(0),
    boundingBox()
{
}

Shape::~Shape()
{
}

void Shape::computeNormals() {
   for (size_t v = 0; v < eleBuf.size()/3; v++) {
      int idx1 = eleBuf[3*v+0];
      int idx2 = eleBuf[3*v+1];
      int idx3 = eleBuf[3*v+2];

      Vector3d p1(posBuf[3*idx1+0], posBuf[3*idx1+1], posBuf[3*idx1+2]);
      Vector3d p2(posBuf[3*idx2+0], posBuf[3*idx2+1], posBuf[3*idx2+2]);
      Vector3d p3(posBuf[3*idx3+0], posBuf[3*idx3+1], posBuf[3*idx3+2]);

      Vector3d vec1 = p2 - p1;
      Vector3d vec2 = p3 - p1;

      Vector3d normal = vec1.cross(vec2);

      // Add this normal to all of the vertices
      norBuf[3*idx1+0] += normal[0];
      norBuf[3*idx1+1] += normal[1];
      norBuf[3*idx1+2] += normal[2];
      norBuf[3*idx2+0] += normal[0];
      norBuf[3*idx2+1] += normal[1];
      norBuf[3*idx2+2] += normal[2];
      norBuf[3*idx3+0] += normal[0];
      norBuf[3*idx3+1] += normal[1];
      norBuf[3*idx3+2] += normal[2];
   }
   // Normalize the normal vectors
   for (size_t v = 0; v < eleBuf.size()/3; v++) {
      int idx1 = eleBuf[3*v+0];
      int idx2 = eleBuf[3*v+1];
      int idx3 = eleBuf[3*v+2];

      Vector3d n1(norBuf[3*idx1+0], norBuf[3*idx1+1], norBuf[3*idx1+2]);
      Vector3d n2(norBuf[3*idx2+0], norBuf[3*idx2+1], norBuf[3*idx2+2]);
      Vector3d n3(norBuf[3*idx3+0], norBuf[3*idx3+1], norBuf[3*idx3+2]);

      Vector3d normalized1 = n1.normalized();
      Vector3d normalized2 = n2.normalized();
      Vector3d normalized3 = n3.normalized();

      norBuf[3*idx1+0] = normalized1[0];
      norBuf[3*idx1+1] = normalized1[1];
      norBuf[3*idx1+2] = normalized1[2];
      norBuf[3*idx2+0] = normalized2[0];
      norBuf[3*idx2+1] = normalized2[1];
      norBuf[3*idx2+2] = normalized2[2];
      norBuf[3*idx3+0] = normalized3[0];
      norBuf[3*idx3+1] = normalized3[1];
      norBuf[3*idx3+2] = normalized3[2];
   }
}

void Shape::loadMesh(const string &meshName)
{
	// Load geometry
	// Some obj files contain material information.
	// We'll ignore them for this assignment.
	vector<tinyobj::shape_t> shapes;
	vector<tinyobj::material_t> objMaterials;
	string errStr;
	bool rc = tinyobj::LoadObj(shapes, objMaterials, errStr, meshName.c_str());
	if(!rc) {
		cerr << errStr << endl;
	} else {
		posBuf = shapes[0].mesh.positions;
		// norBuf = shapes[0].mesh.normals;
		texBuf = shapes[0].mesh.texcoords;
		eleBuf = shapes[0].mesh.indices;

      // Initialize normal array to 0s
      for (size_t v = 0; v < posBuf.size(); v++) {
         norBuf.push_back(0);
      }

      computeNormals();
	}
}

void Shape::resize() {
  float minX, minY, minZ;
   float maxX, maxY, maxZ;
   float scaleX, scaleY, scaleZ;
   float shiftX, shiftY, shiftZ;
   float epsilon = 0.001;

   minX = minY = minZ = 1.1754E+38F;
   maxX = maxY = maxZ = -1.1754E+38F;

   //Go through all vertices to determine min and max of each dimension
   for (size_t v = 0; v < posBuf.size() / 3; v++) {
		if(posBuf[3*v+0] < minX) minX = posBuf[3*v+0];
		if(posBuf[3*v+0] > maxX) maxX = posBuf[3*v+0];

		if(posBuf[3*v+1] < minY) minY = posBuf[3*v+1];
		if(posBuf[3*v+1] > maxY) maxY = posBuf[3*v+1];

		if(posBuf[3*v+2] < minZ) minZ = posBuf[3*v+2];
		if(posBuf[3*v+2] > maxZ) maxZ = posBuf[3*v+2];
	}

	//From min and max compute necessary scale and shift for each dimension
   float maxExtent, xExtent, yExtent, zExtent;
   xExtent = maxX-minX;
   yExtent = maxY-minY;
   zExtent = maxZ-minZ;
   if (xExtent >= yExtent && xExtent >= zExtent) {
      maxExtent = xExtent;
   }
   if (yExtent >= xExtent && yExtent >= zExtent) {
      maxExtent = yExtent;
   }
   if (zExtent >= xExtent && zExtent >= yExtent) {
      maxExtent = zExtent;
   }
   scaleX = 2.0 /maxExtent;
   shiftX = minX + (xExtent/ 2.0);
   scaleY = 2.0 / maxExtent;
   shiftY = minY + (yExtent / 2.0);
   scaleZ = 2.0/ maxExtent;
   shiftZ = minZ + (zExtent)/2.0;

   //Go through all verticies shift and scale them
	for (size_t v = 0; v < posBuf.size() / 3; v++) {
		posBuf[3*v+0] = (posBuf[3*v+0] - shiftX) * scaleX;
		assert(posBuf[3*v+0] >= -1.0 - epsilon);
		assert(posBuf[3*v+0] <= 1.0 + epsilon);
		posBuf[3*v+1] = (posBuf[3*v+1] - shiftY) * scaleY;
		assert(posBuf[3*v+1] >= -1.0 - epsilon);
		assert(posBuf[3*v+1] <= 1.0 + epsilon);
		posBuf[3*v+2] = (posBuf[3*v+2] - shiftZ) * scaleZ;
		assert(posBuf[3*v+2] >= -1.0 - epsilon);
		assert(posBuf[3*v+2] <= 1.0 + epsilon);
	}
}

void Shape::computeBoundingBox() {
	float minX, minY, minZ;
	float maxX, maxY, maxZ;

	minX = minY = minZ = 1.1754E+38F;
	maxX = maxY = maxZ = -1.1754E+38F;


	//Go through all vertices to determine min and max of each dimension
	for (size_t v = 0; v < posBuf.size() / 3; v++) {
		if (posBuf[3 * v + 0] < minX) minX = posBuf[3 * v + 0];
		if (posBuf[3 * v + 0] > maxX) maxX = posBuf[3 * v + 0];

		if (posBuf[3 * v + 1] < minY) minY = posBuf[3 * v + 1];
		if (posBuf[3 * v + 1] > maxY) maxY = posBuf[3 * v + 1];

		if (posBuf[3 * v + 2] < minZ) minZ = posBuf[3 * v + 2];
		if (posBuf[3 * v + 2] > maxZ) maxZ = posBuf[3 * v + 2];
	}

    boundingBox.min = vec3(minX, minY, minZ);
    boundingBox.max = vec3(maxX, maxY, maxZ);

	/*cout << boundingBox.min.x;
	cout << boundingBox.min.y;
	cout << boundingBox.min.z;
	cout << boundingBox.max.x;
	cout << boundingBox.max.y;
	cout << boundingBox.max.z;*/

	

}

void Shape::init()
{
   // Initialize the vertex array object
   glGenVertexArrays(1, &vaoID);
   glBindVertexArray(vaoID);

   //ComputeBoundingBox
   computeBoundingBox();

	// Send the position array to the GPU
	glGenBuffers(1, &posBufID);
	glBindBuffer(GL_ARRAY_BUFFER, posBufID);
	glBufferData(GL_ARRAY_BUFFER, posBuf.size()*sizeof(float), &posBuf[0], GL_STATIC_DRAW);
	
	// Send the normal array to the GPU
	if(norBuf.empty()) {
		norBufID = 0;
	} else {
		glGenBuffers(1, &norBufID);
		glBindBuffer(GL_ARRAY_BUFFER, norBufID);
		glBufferData(GL_ARRAY_BUFFER, norBuf.size()*sizeof(float), &norBuf[0], GL_STATIC_DRAW);
	}
	
	// Send the texture array to the GPU
	if(texBuf.empty()) {
		texBufID = 0;
	} else {
		glGenBuffers(1, &texBufID);
		glBindBuffer(GL_ARRAY_BUFFER, texBufID);
		glBufferData(GL_ARRAY_BUFFER, texBuf.size()*sizeof(float), &texBuf[0], GL_STATIC_DRAW);
	}
	
	// Send the element array to the GPU
	glGenBuffers(1, &eleBufID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eleBufID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, eleBuf.size()*sizeof(unsigned int), &eleBuf[0], GL_STATIC_DRAW);
	
	// Unbind the arrays
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
	assert(glGetError() == GL_NO_ERROR);
}
 
void Shape::draw(const shared_ptr<Program> prog) const
{
	int h_pos, h_nor, h_tex;
	h_pos = h_nor = h_tex = -1;

   glBindVertexArray(vaoID);
	// Bind position buffer
	h_pos = prog->getAttribute("vertPos");
	GLSL::enableVertexAttribArray(h_pos);
	glBindBuffer(GL_ARRAY_BUFFER, posBufID);
	glVertexAttribPointer(h_pos, 3, GL_FLOAT, GL_FALSE, 0, (const void *)0);
	
	// Bind normal buffer
	h_nor = prog->getAttribute("vertNor");
	if(h_nor != -1 && norBufID != 0) {
		GLSL::enableVertexAttribArray(h_nor);
		glBindBuffer(GL_ARRAY_BUFFER, norBufID);
		glVertexAttribPointer(h_nor, 3, GL_FLOAT, GL_FALSE, 0, (const void *)0);
	}

	if (texBufID != 0) {	
		// Bind texcoords buffer
		h_tex = prog->getAttribute("vertTex");
		if(h_tex != -1 && texBufID != 0) {
			GLSL::enableVertexAttribArray(h_tex);
			glBindBuffer(GL_ARRAY_BUFFER, texBufID);
			glVertexAttribPointer(h_tex, 2, GL_FLOAT, GL_FALSE, 0, (const void *)0);
		}
	}

	// Bind element buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eleBufID);
	
	// Draw
	glDrawElements(GL_TRIANGLES, (int)eleBuf.size(), GL_UNSIGNED_INT, (const void *)0);
	
	// Disable and unbind
	if(h_tex != -1) {
		GLSL::disableVertexAttribArray(h_tex);
	}
	if(h_nor != -1) {
		GLSL::disableVertexAttribArray(h_nor);
	}
	GLSL::disableVertexAttribArray(h_pos);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

BoundingBoxComponent *Shape::getBoundingBoxWithTransform(const mat4 transform) {
    vec3 min = boundingBox.min;
    vec3 max = boundingBox.max;
    
    vec4 corners[8];

    corners[0] = transform * vec4(min[0], min[1], min[2], 1);
    corners[1] = transform * vec4(min[0], min[1], max[2], 1);
    corners[2] = transform * vec4(min[0], max[1], min[2], 1);
    corners[3] = transform * vec4(min[0], max[1], max[2], 1);
    corners[4] = transform * vec4(max[0], min[1], min[2], 1);
    corners[5] = transform * vec4(max[0], min[1], max[2], 1);
    corners[6] = transform * vec4(max[0], max[1], min[2], 1);
    corners[7] = transform * vec4(max[0], max[1], max[2], 1);
    vec4 newMin(corners[0].x, corners[0].y, corners[0].z, corners[0].w);
    vec4 newMax(corners[0].x, corners[0].y, corners[0].z, corners[0].w);
    
    // Recompute max and min
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < 8; j++) {
            if (corners[j][i] < newMin[i]) {
                newMin[i] = corners[j][i];
            }
            if (corners[j][i] > newMax[i]) {
                newMax[i] = corners[j][i];
            }
        }
    }
    
    BoundingBoxComponent *bb = new BoundingBoxComponent();
    bb->min = newMin;
    bb->max = newMax;
    return bb;
}
