#include "UtilityNPC.h"


void UtilityNPC::selectAction(float a_fdeltaTime)
{
	m_waterValue.setValue(getWaterValue());
	m_foodValue.setValue(getFoodValue());
	m_treeValue.setValue(getNumberOfLogs());
	m_restValue.setValue(getRestValue());
	
	float fBestScore = 0.0f;
	std::string strBestAction = "buildHouse";
	for (auto score : m_pUtilityScoreMap)
	{
		float fThisScore = score.second->getUtilityScore();
		if (fThisScore > fBestScore)
		{
			fBestScore = fThisScore;
			strBestAction = score.first;
		}
	}

	if (strBestAction == "collectWater")
	{
		collectWater(a_fdeltaTime);
	}

	if (strBestAction == "collectFood")
	{
		collectFood(a_fdeltaTime);
	}

	if (strBestAction == "chopTree")
	{
		chopTree(a_fdeltaTime);
	}
	
	if (strBestAction == "rest")
	{
		rest(a_fdeltaTime);
	}

	if (strBestAction == "buildHouse")
	{
		buildHouse(a_fdeltaTime);
	}
}

