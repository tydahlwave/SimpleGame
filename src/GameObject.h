#pragma once
#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include "MatrixStack.h"

class GameObject {
public:
   Vector3f pos;
   Vector3f size;

   GameObject();
   virtual ~GameObject() {}

   void update(World& world, Graphics& graphics);
private:
};




   Terrain();
   virtual ~Terrain();
   void generate();
   void update(float posX, float posY, float posZ);
   void init();
   void resize();
   void draw(const std::shared_ptr<Program> prog) const;
   void setChunkSize(int size);
   float getHeight(int posX, int posZ);
   
private:
   void computeNormals(int chunkIndex);
   void shiftChunks(int dir);
   void clearChunk(int row, int col);
   void generateChunk(int row, int col);
   void printChunks();
   std::vector<unsigned int> eleBuf[25];
   std::vector<float> posBuf[25];
   std::vector<float> norBuf[25];
   std::vector<float> texBuf[25];
   unsigned eleBufID[25];
   unsigned posBufID[25];
   unsigned norBufID[25];
   unsigned texBufID[25];
   unsigned vaoID;

   int chunkSize;
   module::Perlin myModule;
};

#endif
