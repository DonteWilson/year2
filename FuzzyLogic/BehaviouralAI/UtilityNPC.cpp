#include "UtilityNPC.h"


void UtilityNPC::selectAction(float a_fdeltaTime)
{
	m_waterValue.setValue(getWaterValue());

	float fBestScore = 0.0f;
	std::string strBestAction;
	for (auto score : m_pUtilityScoreMap)
	{
		float fThisScore = score.second->getUtilityScore();
		if (fThisScore > fBestScore)
		{
			fBestScore = fThisScore;
			strBestAction = score.first;
		}
	}
}

