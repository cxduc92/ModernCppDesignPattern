################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ObserverPattern/DummyProduct.cpp \
../src/ObserverPattern/Shop.cpp \
../src/ObserverPattern/Subject.cpp 

OBJS += \
./src/ObserverPattern/DummyProduct.o \
./src/ObserverPattern/Shop.o \
./src/ObserverPattern/Subject.o 

CPP_DEPS += \
./src/ObserverPattern/DummyProduct.d \
./src/ObserverPattern/Shop.d \
./src/ObserverPattern/Subject.d 


# Each subdirectory must supply rules for building sources it contributes
src/ObserverPattern/%.o: ../src/ObserverPattern/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


