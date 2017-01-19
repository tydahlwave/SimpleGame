//
//  ShaderSystem.cpp
//  SimpleGame
//
//  Created by Tyler Dahl on 1/19/17.
//
//

#include <stdio.h>

#include "ShaderSystem.h"

static const string RESOURCE_DIR = "../../resources/";

void ShaderSystem::loadPhong() {
    shared_ptr<Program> shader = make_shared<Program>();
    shader->setVerbose(true);
    shader->setShaderNames(RESOURCE_DIR + "phong_vert.glsl", RESOURCE_DIR + "phong_frag.glsl");
    shader->init();
    shader->addUniform("P");
    shader->addUniform("M");
    shader->addUniform("V");
    shader->addAttribute("vertPos");
    shader->addAttribute("vertNor");
    shader->addUniform("lightPos");
    shader->addUniform("lightColor");
    shader->addUniform("sunDir");
    shader->addUniform("sunColor");
    shader->addUniform("matDiffuseColor");
    shader->addUniform("matSpecularColor");
    shader->addUniform("matAmbientColor");
    shader->addUniform("matShine");
    shaders["phong"] = shader;
}

void ShaderSystem::loadGround() {
    shared_ptr<Program> shader = make_shared<Program>();
    shader->setVerbose(true);
    shader->setShaderNames(RESOURCE_DIR + "ground_vert.glsl", RESOURCE_DIR + "ground_frag.glsl");
    shader->init();
    shader->addUniform("P");
    shader->addUniform("M");
    shader->addUniform("V");
    shader->addAttribute("vertPos");
    shader->addAttribute("vertNor");
    shader->addUniform("lightPos");
    shader->addUniform("lightColor");
    shader->addUniform("sunDir");
    shader->addUniform("sunColor");
    shader->addUniform("matDiffuseColor");
    shader->addUniform("matSpecularColor");
    shader->addUniform("matAmbientColor");
    shader->addUniform("matShine");
    shaders["ground"] = shader;
}
