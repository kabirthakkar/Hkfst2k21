def get_input_len(x):
    print(f"Your inserted value has a length of {len(x)}") 
    
def get_input_data_type(x):
    print (f"{type(x)}")

def convert_input_if_digit(x):
    if(not x.isalpha() and x.find(',') == -1): 
        if(x.find(".") != -1): #When find() returns the position of the caracter, when not return -1
            x = float(x)
        else:
            x = int(x)
    return x




while(1):
    x = input("\nInsert a float value or an integer value or a string value: ")

    
    get_input_len(x)
    x = convert_input_if_digit(x)
    get_input_data_type(x)

    exit = input("\nDo you want to continue? ")

    if(exit.upper() == "SI" or exit.upper() == "YES"):
        continue
    elif(exit.upper() == "NO"):
        break
