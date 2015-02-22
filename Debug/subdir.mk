################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BPQ.cpp \
../KdNode.cpp \
../KdTree.cpp \
../Point.cpp \
../PointCloud.cpp \
../kn.cpp \
../main.cpp \
../testKdTree.cpp \
../testKdTreeRadius.cpp 

OBJS += \
./BPQ.o \
./KdNode.o \
./KdTree.o \
./Point.o \
./PointCloud.o \
./kn.o \
./main.o \
./testKdTree.o \
./testKdTreeRadius.o 

CPP_DEPS += \
./BPQ.d \
./KdNode.d \
./KdTree.d \
./Point.d \
./PointCloud.d \
./kn.d \
./main.d \
./testKdTree.d \
./testKdTreeRadius.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


