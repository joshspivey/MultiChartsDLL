// MultiChartsDLL.cpp : Defines the exported functions for the DLL application.
//

#include "Python.h"
#include "stdafx.h"
#include "MultiChartsDLL.h"
#include <pyhelper.hpp>

MultiCharts::MultiCharts()
{
	intNumber = 10;
	doubleNumber = 902.21;
	stringData = new char[1000]();
	doubleArray = new double[10] ();
}

MultiCharts::~MultiCharts()
{
	delete doubleArray;
	delete stringData;
	doubleArray = NULL;
	stringData = NULL;
	
	/*
	delete trainingData;
	delete dateArray;
	delete fileName;
	delete volumeArray;

	trainingData = NULL;
	dateArray = NULL;
	fileName = NULL;
	volumeArray = NULL;
	*/

}

void MultiCharts::SetIntNumber(int intNumber)
{
	this->intNumber = intNumber;
}

int MultiCharts::GetIntNumber()
{
	return this->intNumber;
}

double MultiCharts::GetDoubleNumber()
{
	return this->doubleNumber;
}

void MultiCharts::SetDoubleNumber(double number)
{
	this->doubleNumber = number;
}

void MultiCharts::InitStringData(int size)
{
	this->stringData = new char[size];
}
	
char* MultiCharts::GetStringData()
{
	return this->stringData	;
}

void MultiCharts::SetStringData(char* stringData)
{
	this->stringData = stringData;
}

double* MultiCharts::GetDoubleArray()
{
	return this->doubleArray;
}


void MultiCharts::InitDoubleArray(int size)
{
	this->doubleArray = new double[size];
}

void MultiCharts::SetDoubleArray(double* doubleArray)
{
	this->doubleArray = doubleArray;
}


char* MultiCharts::GetPythonStringData()
{
	CPyInstance hInstance;

	CPyObject pModule = PyImport_ImportModule("build");
	if (pModule)
	{
		CPyObject pFunc = PyObject_GetAttrString(pModule, "train");
		if (pFunc)
		{
			CPyObject pList = PyList_New(0);
			PyList_Append(pList, );
			CPyObject pValue = PyObject_CallObject(pFunc, NULL);
			pythonStringData = PyUnicode_AsUTF8(pValue);
			return pythonStringData;
		}
		else 
		{
			pythonStringData = new char[4] {"101"};
			return pythonStringData;
		}
	}
	else
	{
		pythonStringData = new char[4] {"102"};
		return pythonStringData;
	}
}

void MultiCharts::InitPythonStringData(int size)
{
	this->pythonStringData = new char[size];
}

void MultiCharts::SetPythonStringData(char* pythonStringData)
{
	this->pythonStringData = pythonStringData;
}
	
MultiCharts* CreateMultiCharts()
{
	return new MultiCharts();
}

void DisposeMultiCharts(MultiCharts* multiCharts)
{
	if (multiCharts != NULL)
	{
		delete multiCharts;
		multiCharts = NULL;
	}
}

void SetIntNumber(MultiCharts* multiCharts, int intNumber)
{
	if (multiCharts != NULL) 
	{
		multiCharts->SetIntNumber(intNumber);
	}
}

int GetIntNumber(MultiCharts* multiCharts)
{
	if (multiCharts != NULL)
	{
		return multiCharts->GetIntNumber();
	}
	return 0;
}

double GetDoubleNumber(MultiCharts* multiCharts)
{
	if (multiCharts != NULL)
	{
		return multiCharts->GetDoubleNumber();
	}
	return 0.0;
}

char* GetStringData(MultiCharts* multiCharts)
{
	if (multiCharts != NULL)
	{
		return multiCharts->GetStringData();
	}
	return NULL;
}

void InitStringData(MultiCharts* multiCharts, int size)
{
	if (multiCharts != NULL)
	{
		multiCharts->InitStringData(size);
	}
}

double* GetDoubleArray(MultiCharts* multiCharts)
{
	if (multiCharts != NULL)
	{
		return multiCharts->GetDoubleArray();
	}
	return NULL;
}

void SetDoubleNumber(MultiCharts* multiCharts, double doubleNumber)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetDoubleNumber(doubleNumber);
	}
}

void SetStringData(MultiCharts* multiCharts, char* stringData)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetStringData(stringData);
	}
}

void InitDoubleArray(MultiCharts* multiCharts, int size)
{
	if (multiCharts != NULL)
	{
		multiCharts->InitDoubleArray(size);
	}
}

void SetDoubleArray(MultiCharts* multiCharts, double* doubleArray)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetDoubleArray(doubleArray);
	}

}

char* GetPythonStringData(MultiCharts* multiCharts)
{
	if (multiCharts != NULL)
	{
		return multiCharts->GetPythonStringData();
	}
	return NULL;
}

void SetPythonStringData(MultiCharts* multiCharts, char* pythonStringData)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetPythonStringData(pythonStringData);
	}
}

void InitPythonStringData(MultiCharts* multiCharts, int size)
{
	if (multiCharts != NULL)
	{
		 multiCharts->GetPythonStringData();
	}
}

/*

void InitTrainingData(MultiCharts * multiCharts, int size)
{
	if (multiCharts != NULL)
	{
		multiCharts->InitTrainingData(size);
	}
}

void SetTrainingData(MultiCharts* multiCharts, double* trainingData)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetTrainingData(trainingData);
	}
}

void InitDateArray(MultiCharts * multiCharts, int size)
{
	if (multiCharts != NULL)
	{
		multiCharts->InitTrainingData(size);
	}
}

void SetDateArray(MultiCharts * multiCharts, char(*dateArray)[DATE_SIZE])
{
	if (multiCharts != NULL)
	{
		multiCharts->SetDateArray(dateArray);
	}
}

void InitVolumeArray(MultiCharts * multiCharts, int size)
{
	if (multiCharts != NULL)
	{
		multiCharts->InitTrainingData(size);
	}
}

void SetVolumeArray(MultiCharts * multiCharts, long * volumeArray)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetVolumeArray(volumeArray);
	}
}

void InitFileName(MultiCharts * multiCharts, int size)
{
	if (multiCharts != NULL)
	{
		multiCharts->InitTrainingData(size);
	}
}

void SetFileName(MultiCharts * multiCharts, char * fileName)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetFileName(fileName);
	}
}

void SetLearningRate(MultiCharts * multiCharts, double learningRate)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetLearningRate(learningRate);
	}
}

void SetEpochs(MultiCharts * multiCharts, int epochs)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetEpochs(epochs);
	}
}

void SetScale(MultiCharts * multiCharts, int scale)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetScale(scale);
	}
}

*/