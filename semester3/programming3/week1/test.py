class Test(object):
    def __init__(self, subject_name, correct_answers, passing_mark):
        self.subject_name = subject_name
        self.correct_answers = correct_answers
        self.passing_mark = float(passing_mark.strip('%'))

paper1 = Test('Maths', ['1A', '2C', '3D', '4A', '5A'], '60%')
paper2 = Test('Chemistry', ['1C', '2C', '3D', '4A'], '75%')
paper3 = Test('Computing', ['1D', '2C', '3C', '4B', '5D', '6C', '7A'], '75%')

class Student(object):
    def __init__(self, name):
        self.name = name

    def take_test(self, test, answers):
        total_questions = len(test.correct_answers)
        correct = 0
        for student_answer, correct_answer in zip(answers, test.correct_answers):
            if student_answer == correct_answer:
                correct += 1

        percentage = (correct / total_questions) * 100

        if percentage >= test.passing_mark:
            print("{} passed the {} test with the score {}%". format(self.name, test.subject_name, percentage))
        else:
            print("{} failed the {} test!".format(self.name, test.subject_name))

stu1 = Student('Tom')
stu1.take_test(paper2,['1C', '3C', '3D', '4A'])

stu2 = Student('John')
stu2.take_test(paper1, ['1B', '2C', '3A', '4A', '5B'])
