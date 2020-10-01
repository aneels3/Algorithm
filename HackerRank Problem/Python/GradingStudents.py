def gradingStudents(grades):
    op_grades = []
    for grade in grades:
        ng = grade
        if grade >= 38 and (grade % 5 != 0):
            for num in (1,2):
                new_grade = grade + num
                if new_grade % 5 == 0:
                    ng = new_grade
        op_grades.append(ng)
    return op_grades


if __name__ == '__main__':
    grades_count = int(input().strip())
    grades = []
    for _ in range(grades_count):
        grades_item = int(input().strip())
        grades.append(grades_item)
    result = gradingStudents(grades)
    print(result)