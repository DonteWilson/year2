#ifndef UTILITY_NPC_H_
#define UTILITY_NPC_H_

#include "BaseNPC.h"
#include "UtilityValue.h"
#include "UtilityScore.h"

#include <iostream>
#include <map>

#include "Gizmos.h"
#include "World.h"

#include "gl_core_4_4.h"
#include <GLFW\glfw3.h>

using namespace UtilitySystem;

class UtilityNPC : public BaseNPC
{
	public:
		UtilityNPC(World* pWorld) : BaseNPC(pWorld)
		{
			m_waterValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_waterValue.setMinMaxValues(0, 10);
			m_waterValue.setValue(getWaterValue());

			m_foodValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_foodValue.setMinMaxValues(0, 20);
			m_foodValue.setValue(getFoodValue());

			m_treeValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_treeValue.setMinMaxValues(0, 2);
			m_treeValue.setValue(getNumberOfLogs());


			m_restValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_restValue.setMinMaxValues(0, 15);
			m_restValue.setValue(getNumberOfLogs());

			/*m_buildValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_buildValue.setMinMaxValues(0, 20);
			m_buildValue.setValue(getNumberOfLogs());
*/
			

			
			UtilityScore* pWaterScore = new UtilityScore();
			pWaterScore->addUtilityValue(&m_waterValue, 1.0f);
			m_pUtilityScoreMap["collectWater"] = pWaterScore;

			UtilityScore* pFoodScore = new UtilityScore();
			pFoodScore->addUtilityValue(&m_foodValue, 1.0f);
			m_pUtilityScoreMap["collectFood"] = pFoodScore;

			UtilityScore* pTreeScore = new UtilityScore();
			pTreeScore->addUtilityValue(&m_treeValue, 1.0f);
			m_pUtilityScoreMap["chopTree"] = pTreeScore;

			UtilityScore* pRestScore = new UtilityScore();
			pRestScore->addUtilityValue(&m_restValue, 1.0f);
			m_pUtilityScoreMap["rest"] = pRestScore;


			


		}
		~UtilityNPC() {}

	protected:
		void selectAction(float a_fdeltaTime) override;

private:
	UtilityValue m_waterValue;
	UtilityValue m_foodValue;
	UtilityValue m_treeValue;
	UtilityValue m_restValue;
	UtilityValue m_buildValue;
	std::map<std::string, UtilityScore* > m_pUtilityScoreMap;


};



#endif
