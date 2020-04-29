import unittest
import Part_Edition
class TestMathFunc(unittest.TestCase):
    global testList
    testList= Part_Edition.getProgramList(5, ['+', '-'], 10, 1, 0, 1)
    global testAnswerList
    testAnswerList= Part_Edition.Compute_Answer(5, 1, 0, testList)
    def test_0(self):
        self.assertEqual(eval(testList[0]), testAnswerList[0],'Equal')
    def test_1(self):
        self.assertEqual(eval(testList[1]), testAnswerList[1], 'Equal')
    def test_2(self):
        self.assertEqual(eval(testList[2]), testAnswerList[2], 'Equal')
    def test_3(self):
        self.assertEqual(eval(testList[3]), testAnswerList[3], 'Equal')
if __name__ == 'main':
    unittest.main()