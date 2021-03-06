//- ------------------------------------------------------------------
//-    Copyright (c) James W. Grenning -- All Rights Reserved         
//-    For use by owners of Test-Driven Development for Embedded C,   
//-    and attendees of Renaissance Software Consulting, Co. training 
//-    classes.                                                       
//-                                                                   
//-    Available at http://pragprog.com/titles/jgade/                 
//-        ISBN 1-934356-62-X, ISBN13 978-1-934356-62-3               
//-                                                                   
//-    Authorized users may use this source code in your own          
//-    projects, however the source code may not be used to           
//-    create training material, courses, books, articles, and        
//-    the like. We make no guarantees that this source code is       
//-    fit for any purpose.                                           
//-                                                                   
//-    www.renaissancesoftware.net james@renaissancesoftware.net      
//- ------------------------------------------------------------------

extern "C"
{
#include "X10LightDriver.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(X10LightDriver)
{
    X10LightDriver x10LightDriver;
    LightDriver lightDriver;

    void setup()
    {
      lightDriver = X10LightDriver_Create(3, X10_A, 12);
      X10LightDriver_InstallInterface();
    }

    void teardown()
    {
       LightDriver_Destroy(lightDriver);
    }
};

TEST(X10LightDriver, Create)
{
    LONGS_EQUAL(3, LightDriver_GetId(lightDriver));
    STRCMP_EQUAL("X10", LightDriver_GetType(lightDriver));
}

