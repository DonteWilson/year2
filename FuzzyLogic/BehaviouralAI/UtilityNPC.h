#ifndef UTILITY_NPC_H_
#define UTILITY_NPC_H_

#include "src\BaseNPC.h"
#include "src\UtilityValue.h"
#include "src\UtilityScore.h"

#include <iostream>
#include <map>

#include "src\Gizmos.h"
#include "src\World.h"

#include "src\gl_core_4_4.h"
#include <GLFW\glfw3.h>

using namespace UtilitySystem;

class UtilityNPC : public BaseNPC
{
	public:
		UtilityNPC(World* pWorld) : BaseNPC(pWorld)
		{
			m_waterValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
			m_waterValue.setMinMaxValues(0, 20);
			m_waterValue.setValue(getWaterValue());

			UtilityScore* pWaterScore = new UtilityScore();
			pWaterScore->addUtilityValue(&m_waterValue, 1.0f);
			m_pUtilityScoreMap["collectWater"] = pWaterScore;

		}
		~UtilityNPC();

	protected:
		void selectAction(float a_fdeltaTime) override;

private:
	UtilityValue m_waterValue;
	std::map<std::string, UtilityScore* > m_pUtilityScoreMap;


};



#endif
