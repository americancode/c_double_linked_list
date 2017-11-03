################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LinkedList/LinkedList.c \
../LinkedList/LinkedListIterator.c \
../LinkedList/LinkedListNode.c 

OBJS += \
./LinkedList/LinkedList.o \
./LinkedList/LinkedListIterator.o \
./LinkedList/LinkedListNode.o 

C_DEPS += \
./LinkedList/LinkedList.d \
./LinkedList/LinkedListIterator.d \
./LinkedList/LinkedListNode.d 


# Each subdirectory must supply rules for building sources it contributes
LinkedList/%.o: ../LinkedList/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


