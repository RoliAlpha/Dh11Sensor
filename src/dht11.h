#pragma once
#ifndef _dht11_h
#define _dht11_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define DHTLIB_OK				0
#define DHTLIB_ERROR_CHECKSUM	-1
#define DHTLIB_ERROR_TIMEOUT	-2

#include<SensorBase.h>
class dht11 :public SensorBase
{
public:
	dht11(int pinNo);
	~dht11();
	virtual int GetChnanelNum() override;
	virtual int Update() override;
	virtual float Read(int chanelNo) override;
	virtual int Write(int channelNo, float value, bool isAsync = false) override
	{
	}

private:
	double Fahrenheit(double celsius); //�����¶ȶ�ת��Ϊ�����¶�
	double Kelvin(double celsius); //�����¶�ת��Ϊ�����¶�
	double dewPoint(double celsius, double humidity);// ¶�㣨���ڴ��¶�ʱ���������Ͳ�����¶�飩
													 // �ο�: http://wahiduddin.net/calc/density_algorithms.htm 
	double dewPointFast(double celsius, double humidity);// ���ټ���¶�㣬�ٶ���5��dewPoint()
														 // �ο�: http://en.wikipedia.org/wiki/Dew_point
	//void Cheak();//����Ƿ�ʱ��һЩ���
	int humidity;//channelNo 1
	int temperature;//channelNo 0
	int TotalChannel=2;//�����ܵ�channel����
	int pinNo;//��������
};



#endif // !dht11_h

