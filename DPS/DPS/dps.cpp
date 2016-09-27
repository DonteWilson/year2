#include <iostream>

class Weapon
{
public:
	Weapon(){}
	float GetDps(Weapon w);

protected:
	float m_spd;
	float m_high;
	float m_low;


};

class MP7 : public Weapon
{
public:
	MP7(const float m_high,const float m_low, const float m_spd);

};


class AK : public Weapon
{
	
};

class MSR : public Weapon
{
	
};


float Weapon::GetDps(Weapon w)
{
	return((w.m_high + w.m_low) / 2) / w.m_spd;
}

int main()
{
	
	MP7 mp;
	mp.m_high = 74.0f;
	mp.m_low = 32.0f;
	mp.m_spd = 2.00f;

	AK aka;
	aka.m_high = 85.0f;
	aka.m_low = 30.0f;
	aka.m_spd = 1.58f;

	MSR sniper;
	sniper.m_high = 110.0f;
	sniper.m_low = 56.0f;
	sniper.m_spd = 3.00f;
	


	float MP = GetDps(mp);
	float AK = GetDps(aka);
	float MSR = GetDps(sniper);

	std::cout << "MP7 Dps: " << MP << std::endl;
	std::cout << "AK47 Dps: " << AK << std::endl;
	std::cout << "MSR Dps: " << MSR << std::endl;

	system("pause");
	return 0;
}