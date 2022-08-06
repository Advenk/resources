#!/usr/bin/env python3
# This module takes a string and decodes or encodes the given input based on the user decision 
# Planned: Implement flagged arguments to skip the dialogue 
import sys
import base64


print("This script will help you encode or decrypt base64 strings\n")

data = input("Enter the data you would like to encode or decrypt.\n").replace('\n', '') 
data.encode() # .encode() needed to convert input to bytes like onject

option = int(input("Are we decoding or encoding? (1 or 2)\n 1.Encoding\n 2.Decoding\n" ))

if option == 1:
	encoded = base64.b64encode(data)
	print(encoded)	
elif option == 2:
	decoded = base64.b64decode(data)
	print(decoded)
else:
	print("invalid input\n exiting...")
