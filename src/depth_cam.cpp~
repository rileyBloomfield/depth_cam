#include "ros/ros.h"
#include "std_msgs/String.h"
#include <stdio.h>
#include <pmdsdk2.h>
#include "stdlib.h"
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

// on error, prepend absolute path to files before plugin names
#define SOURCE_PLUGIN "camboardnano"
#define SOURCE_PARAM ""
#define PROC_PLUGIN "camboardnanoproc"
#define PROC_PARAM ""

char err[128];

class Camera {
  private:
    PMDHandle camHandle;
    int res;
  public:
    Camera() {
	//Open Camera
    res = pmdOpen (&camHandle, SOURCE_PLUGIN, SOURCE_PARAM, PROC_PLUGIN, PROC_PARAM);
    if (res != PMD_OK) {
        pmdGetLastError (0, err, 128);
        fprintf (stderr, "Could not connect: %s\n", err);
    }
    std::cout<<"Camera was opened"<<std::endl;
    };
    ~Camera() {
	//Close Camera
    res = pmdClose(camHandle);
    if (res != PMD_OK) {
	pmdGetLastError (0, err, 128);
        fprintf (stderr, "Could not close: %s\n", err);
    }
    std::cout<<"Camera was closed"<<std::endl;
    };

void update() {
    //Update Camera
    res = pmdUpdate(camHandle);
    if(res != PMD_OK) {
	printf ("Could not retrieve data\n");
    }
};

void getDescription() {
	//Get Camera Description
    PMDDataDescription dataDesc;
    res = pmdGetSourceDataDescription(camHandle, &dataDesc);
    if (res != PMD_OK) {
	printf("Could not get camera description\n");
    }
    std::cout<<"Sensor resolution: "<<dataDesc.img.numColumns<<"x"<<dataDesc.img.numRows<<std::endl;
}

void getZCoords() {
	//Get Distances
    float data[300000] = {};
    size_t maxLen = 300000;
    res = pmdGet3DCoordinates(camHandle, data, maxLen);
    if (res != PMD_OK) {
	printf("Error retrieving coords\n");
    }
    ofstream file;
    file.open("z-coords.csv"); //Name output file
    int index = 0;
    for(int i=0; i<120; i++) {
	for(int j=0; j<165; j++) {
	    index +=2;
	    if(data[index] > 0.3)
		data[index] = 1.0;
	    if (j == 164) {
		file<<data[index++];
	    }
	    else {
	    file<<data[index++]<<",";
	    }
	}
	file<<"\n";
    }
}
void getDistances() {
}
void getAmplitudes() {
}
void printFiles() {
	getZCoords();
	getDistances();
	getAmplitudes();
}
};

int main(int argc, char** argv) {
	Camera cam = Camera();
	cam.update();

}
