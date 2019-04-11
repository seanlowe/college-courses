import unittest
from skateboard import Skateboard

class TestSkateboard(unittest.TestCase):
    
    def testKickOff(self):
        unit = Skateboard()
        ok = False
        try:
            unit.kickOff()
        except ValueError:
            ok = True
        self.assertTrue(ok)

    def testTailGring(self):
        unit = Skateboard()
        ok = False
        try:
            unit.tailGrind()
        except ValueError:
            ok = True
        self.assertTrue(ok)
                
if __name__ == '__main__':
    unittest.main()
