import serial
import time
from openpyxl import load_workbook



Arduino = serial.Serial(port='COM3',baudrate=9600,timeout=1)
time.sleep(1)

wb = load_workbook("SWAtest.xlsx")
ws = wb.active

T1index = 2
T2index = 2
T3index = 2
T4index = 2
T5index = 2

wb.save("SWAtest.xlsx")

while True:
    rawdata = Arduino.readline()
    data = rawdata.decode('utf-8')
    parsedata = data.split()
    for word in parsedata:
        try:
            if word == "Sensor1":
                index1 = parsedata.index('Sensor1')
                temp1 = parsedata[index1 + 1]
                print(f"Sensor 1 temp is {temp1}")

                ws['B'+str(T1index)].value = temp1
                T1index += 1
                wb.save("SWAtest.xlsx")

            if word == "Sensor2":
                index2 = parsedata.index('Sensor2')
                temp2 = parsedata[index2 + 1]
                print(f"Sensor 2 temp is {temp2}")

                ws['C' + str(T2index)].value = temp2
                T2index += 1
                wb.save("SWAtest.xlsx")

            if word == "Sensor3":
                index3 = parsedata.index('Sensor3')
                temp3 = parsedata[index3 + 1]
                print(f"Sensor 3 temp is {temp3}")

                ws['D' + str(T3index)].value = temp3
                T3index += 1
                wb.save("SWAtest.xlsx")

            if word == "Sensor4":
                index4 = parsedata.index('Sensor4')
                temp4 = parsedata[index4 + 1]
                print(f"Sensor 4 temp is {temp4}")

                ws['E' + str(T4index)].value = temp4
                T4index += 1
                wb.save("SWAtest.xlsx")

            if word == "Sensor5":
                index5 = parsedata.index('Sensor5')
                temp5 = parsedata[index5 + 1]
                print(f"Sensor 5 temp is {temp5}")

                ws['F' + str(T5index)].value = temp5
                T5index += 1
                wb.save("SWAtest.xlsx")

        except IndexError:
            pass