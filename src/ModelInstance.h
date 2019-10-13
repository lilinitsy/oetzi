
#ifndef MODELINSTANCE_H
#define MODELINSTANCE_H

#include <iostream>
#include <string>
#include <vector>

#include "glad/glad.h"  //Include order can matter here
#include <external/stb_image.h>
#include <external/stb_image_write.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>



#include "Mesh.h"



#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"

// This will be the assimp thing

struct ModelInstance
{
	public:
	    std::vector<Texture> textures_loaded;
	    std::vector<Mesh> meshes;
	    std::string directory;
	    bool gammaCorrection;

	private:
	    /*  Functions   */
	    // loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes std::vector.
	    void loadModel(std::string const &path);
	    void processNode(aiNode *node, const aiScene *scene);
	    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

	    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};


unsigned int TextureFromFile(const char *path, const std::string &directory);


#endif