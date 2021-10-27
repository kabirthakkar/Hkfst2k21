# program that requests entry with a student's name,
# after entry enter 10 student grades (all must be entered by the program user)
# and after having the grade list for the student show at the end of the program,
# the student's average, the maximum grade, the minimum grade, the first and the last grade assigned to the student.


def get_last_grade(grades):
    print(f'The last assign grade was {grades[-1]}')

def get_first_grade(grades):
    print(f'The first assign grade was {grades[0]}')

def get_min_grade(grades):
    print(f'The minimum grade was {min(grades)}')

def get_max_grade(grades):
    print(f'The minimum grade was {max(grades)}')

def get_prom_grade(grades):
    print(f'The average grade was {round(sum(grades)/ len(grades), 2)}')


while(1):
    grades = []
    name = str(input('\nInsert the student name: '))

    for i in range(11):
        x = int(input("Insert the grades for this student: "))
        grades.append(x)
    
    print(f"\nThe grades of {name} are: ")
    get_prom_grade(grades)
    get_max_grade(grades)
    get_min_grade(grades)
    get_first_grade(grades)
    get_last_grade(grades)