#include "Model.h"
#include "../TheEngine.h"
#include "../SceneManager/SceneManager.h"
#include "../SceneManager/Scene.h"
#include <string>
namespace LevelUp
{
	int Model::m_numberOfModels = 0;

    Model::Model() : m_canUpdate(true), m_parentScene("")
	{
		m_numberOfModels++;
		addToMap();
	}
	Model::~Model()
	{
        removeFromMap();
	}
	std::string Model::ModelID()
	{
		return m_ID;
	}
	void Model::setCanUpdate(bool b)
	{
		m_canUpdate = b;
	}
	void Model::addToMap()
	{
        //add the map to the current scene or the engine
		m_ID = "Model " + std::to_string(m_numberOfModels);
		Scene* s = getEngine()->getSceneManager()->getActiveScene();
		if (s != nullptr)
		{
            m_parentScene = s->sceneID();
			s->addModel(this);
		}
		else
		{
			getEngine()->addModel(this);
		}
	}

    void Model::removeFromMap()
    {
        //remove the map from the current scene or the engine
        if (m_parentScene != "")
        {
            Scene* s = getEngine()->getSceneManager()->getScene(m_parentScene);
            if (s != nullptr)
            {
                s->removeModel(this);
            }
        }
        else
        {
            getEngine()->removeModel(this);
        }
    }

	bool Model::canUpdate()
	{
		return m_canUpdate;
	}
}