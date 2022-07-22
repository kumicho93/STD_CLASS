COPTS += -DMAKE_EV3
COPTS += -DMAKE_EV3
mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS += \

APPL_CXXOBJS += \
				system.o\
				Motor.o\
				LeftMotor.o\
				RightMotor.o\
#
SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries

include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile
#include $(mkfile_path)/workspace/library/RyujiEv3/Makefile

endif 

# COPTS += -DMAKE_BT_DISABLE

APPL_DIRS +=\
	$(mkfile_path)workspace/src\

INCLUDES +=\
	-I$(mkfile_path)workspace/include\

COPTS += -I$(ETROBO_HRP3_WORKSPACE)/etroboc_common
COPTS += -DMAKE_EV3
COPTS += -DMAKE_EV3
COPTS += -std=gnu++11
COPTS += -fno-threadsafe-statics
COPTS += -DMAKE_EV3
