// MultiChartsDLL.cpp : Defines the exported functions for the DLL application.
//

#include "Python.h"
#include "stdafx.h"
#include "MultiChartsDLL.h"
#include "pyhelper.hpp"

MultiCharts::MultiCharts()
{

}

MultiCharts::~MultiCharts()
{
	/*
	if(trainingData != NULL)
	{
		delete[] trainingData;
		trainingData = NULL;
	}

	if (dateArray)
	{
		delete[] dateArray;
		dateArray = NULL;
	}

	if (fileName)
	{
		delete[] fileName;
		fileName = NULL;
	}

	if (volumeArray)
	{
		delete[] volumeArray;
		volumeArray = NULL;
	}
	*/
}

/*

		--Member Functions--

*/

/*
char* MultiCharts::GetPythonStringData()
{
	CPyInstance hInstance;

	//CPyObject pName = PyUnicode_FromString("build");
	CPyObject pModule = PyImport_ImportModule("build");
	if (pModule)
	{
		CPyObject pFunc = PyObject_GetAttrString(pModule, "getRandomText");
		if (pFunc)
		{
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
*/

void MultiCharts::InitTrainingData(int size)
{
	this->trainingDataSize = size;
}

void MultiCharts::SetTrainingData(double* trainingData)
{
	this->trainingData = trainingData;
}

void MultiCharts::InitDateArray(int size)
{
	this->dateArray = new char[size][DATE_SIZE];
}

void MultiCharts::SetDateArray(char(*dateArray)[DATE_SIZE])
{
	this->dateArray = dateArray;
}

void MultiCharts::InitVolumeArray(int size)
{
	this->volumeArray = new long[size];
}

void MultiCharts::SetVolumeArray(long* volume)
{
	this->volumeArray = volume;
}

void MultiCharts::InitFileName(int size)
{
	this->fileName = new char[size];
}

void MultiCharts::SetFileName(char* fileName)
{
	this->fileName = fileName;
}

void MultiCharts::SetLearningRate(double learningRate)
{
	this->learningRate = learningRate;
}

void MultiCharts::SetEpochs(short epochs)
{
	this->epochs = epochs;
}

void MultiCharts::SetScale(int scale)
{
	this->scale = scale;
}

void MultiCharts::SetOptimizer(short optimizer)
{
	this->optimizer = optimizer;
}

double MultiCharts::TrainModel()
{
	CPyInstance pyInstance;
	CPyObject pModule = PyImport_ImportModule("build");

	if (pModule)
	{
		CPyObject pFunc = PyObject_GetAttrString(pModule, "train");
		if (pFunc && PyCallable_Check(pFunc))
		{
			CPyObject pList = PyList_New(0);
			for (int i = 0; i < trainingDataSize; i++)
			{
				PyList_Append(pList, PyFloat_FromDouble(trainingData[i]));
			}
			/*PyList_Append(pList, PyFloat_FromDouble(100.21));
			PyList_Append(pList, PyFloat_FromDouble(200.09));
			PyList_Append(pList, PyFloat_FromDouble(90.03));*/

			if (pList)
			{
				CPyObject pValue = PyObject_CallFunctionObjArgs(pFunc, pList, NULL);
				pFunc.Release();
				pList.Release();
				if (pValue)
				{
					double num = PyFloat_AsDouble(pValue);
					return num;
				}
				else
				{
					return 1.01;
				}
			}
			else
			{
				return 2.01;
			}
		}
		else
		{
			return 3.01;
		}
	}
	else
	{
		return 4.01;
	}
}

/*

		-- Exported Functions --

*/

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

void InitTrainingData(MultiCharts* multiCharts, int size)
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

void InitDateArray(MultiCharts* multiCharts, int size)
{
	if (multiCharts != NULL)
	{
		multiCharts->InitTrainingData(size);
	}
}

void SetDateArray(MultiCharts* multiCharts, char(*dateArray)[DATE_SIZE])
{
	if (multiCharts != NULL)
	{
		multiCharts->SetDateArray(dateArray);
	}
}

void InitVolumeArray(MultiCharts* multiCharts, int size)
{
	if (multiCharts != NULL)
	{
		multiCharts->InitTrainingData(size);
	}
}

void SetVolumeArray(MultiCharts* multiCharts, long * volumeArray)
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

void SetFileName(MultiCharts* multiCharts, char * fileName)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetFileName(fileName);
	}
}

void SetLearningRate(MultiCharts* multiCharts, double learningRate)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetLearningRate(learningRate);
	}
}

void SetEpochs(MultiCharts* multiCharts, short epochs)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetEpochs(epochs);
	}
}

void SetScale(MultiCharts* multiCharts, int scale)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetScale(scale);
	}
}

void SetOptimizer(MultiCharts* multiCharts, short optimizer)
{
	if (multiCharts != NULL)
	{
		multiCharts->SetOptimizer(optimizer);
	}
}

double TrainModel(MultiCharts* multiCharts)
{
	return multiCharts->TrainModel();
}
