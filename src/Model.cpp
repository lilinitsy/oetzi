#include "Model.h"

#include <fstream>

#include <external/loguru.hpp>

#include "GPU-Includes.h"

// Stephen's functions
Model global_model_list[10000];
unsigned int num_models = 0;

void loadModel(std::string fileName)
{
	LOG_SCOPE_FUNCTION(INFO);

	FILE *fp;
	long length;
	char rawline[1024];
	fp = fopen(fileName.c_str(), "r");

	LOG_F(INFO, "Loading Model File: %s", fileName.c_str());
	CHECK_NOTNULL_F(fp, "Can't open model file '%s'", fileName.c_str());

	fseek(fp, 0, SEEK_END); // move position indicator to the end of the file;
	length = ftell(fp);		// return the value of the current position
	LOG_F(INFO, "File '%s' is %ld bytes long.", fileName.c_str(), length);
	fseek(fp, 0, SEEK_SET); // move position indicator to the start of the file

	std::string modelName = "";
	std::string modelDir = "./";
	int curModelID = 0;
	while(fgets(rawline, 1024, fp))
	{
		std::string line = std::string(rawline);
		if(rawline[0] == '#')
		{
			LOG_F(2, "Skipping comment: %s", rawline);
			continue;
		}

		char command[100];
		int fieldsRead = sscanf(rawline, "%s ", command);
		std::string commandStr = command;

		if(fieldsRead < 1)
		{
			continue;
		}

		// "[" indicates new model
		if(commandStr.substr(0, 1) == "[")
		{
			int closeBrackets = line.find("]");
			CHECK_F(closeBrackets >= 0, "ERROR: Model name opened with [ but not closed with ]");
			modelName = line.substr(1, closeBrackets - 1);
			curModelID = add_model(modelName);
			LOG_F(INFO, "Creating PreFab Model with name: %s", modelName.c_str());
		}

		else if(commandStr == "scale")
		{
			float scaleFactor;
			sscanf(rawline, "scale %f", &scaleFactor);
			global_model_list[curModelID].transform = glm::scale(global_model_list[curModelID].transform, scaleFactor * glm::vec3(1, 1, 1));
			LOG_F(1, "Scaling by %f", scaleFactor);
		}
		else if(commandStr == "scalexyz")
		{
			//compute new glm matrix
			float sx, sy, sz;
			sscanf(rawline, "scalexyz %f %f %f", &sx, &sy, &sz);
			global_model_list[curModelID].transform = glm::scale(global_model_list[curModelID].transform, glm::vec3(sx, sy, sz));
			LOG_F(1, "Scaling by %f %f %f", sx, sy, sz);
		}
		else if(commandStr == "rotate")
		{
			//compute new glm matrix
			float angle, rx, ry, rz;
			sscanf(rawline, "rotate %f %f %f %f", &angle, &rx, &ry, &rz);
			global_model_list[curModelID].transform = glm::rotate(global_model_list[curModelID].transform, (float)(angle * (M_PI / 180.f)), glm::vec3(rx, ry, rz));
			LOG_F(1, "Rotating by %f around axis %f %f %f", angle, rx, ry, rz);
		}
		else if(commandStr == "translate")
		{
			//compute new glm matrix
			float tx, ty, tz;
			sscanf(rawline, "translate %f %f %f", &tx, &ty, &tz);
			global_model_list[curModelID].transform = glm::translate(global_model_list[curModelID].transform, glm::vec3(tx, ty, tz));
			LOG_F(1, "Transling by (%f, %f, %f)", tx, ty, tz);
		}

		else if(commandStr == "modelDir")
		{
			char dirName[1024];
			sscanf(rawline, "modelDir = %s", dirName);
			modelDir = dirName;
			LOG_F(1, "Setting model directory to: %s", modelDir.c_str());
		}

		else if(commandStr == "child")
		{
			int openBracket = line.find("[") + 1;
			int modelNameLength = line.find("]") - openBracket;
			std::string childName = line.substr(openBracket, modelNameLength);
			LOG_F(1, "Adding Child with name %s to model %d", childName.c_str(), curModelID);
			add_child(childName, curModelID);
		}

		else
		{
			LOG_F(WARNING, "WARNING. Unknown model command: %s", commandStr.c_str());
		}
	}
}

void add_child(std::string child_name, int current_model_id)
{
}

int add_model(std::string model_name)
{
	return 1;
}