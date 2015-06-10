#include "ros/ros.h"
#include "std_msgs/String.h"
#include <stdio.h>
#include <pmdsdk2.h>
#include "stdlib.h"
#include <ctime>
#include <iostream>

// on error, prepend absolute path to files before plugin names
#define SOURCE_PLUGIN "camboardnano"
#define SOURCE_PARAM ""
#define PROC_PLUGIN "camboardnanoproc"
#define PROC_PARAM ""

char err[128];

int main(int argc, char** argv) {

PMDHandle hnd;
    int res;

    res = pmdOpen (&hnd, SOURCE_PLUGIN, SOURCE_PARAM, PROC_PLUGIN, PROC_PARAM);
    if (res != PMD_OK)
    {
        pmdGetLastError (0, err, 128);
        fprintf (stderr, "Could not connect: %s\n", err);
        return 1;
    }
ros::Rate rate(5); //5Hz
    printf ("opened sensor\n");
    std::cout<<"Test"<<std::endl;
    return 0;
}