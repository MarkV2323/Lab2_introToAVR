# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).

tests = [{ 

    # Total Weight = 765, WeightDiff = 0, final binary should be 101111 01 or
    # 0xBD
    'description': 'PINA: 0xFF, PINB: 0xFF, PINC: 0xFF  => PORTD: 0xBD',
    'steps': [ {'inputs': [('PINA',0xFF), ('PINB',0xFF), ('PINC',0xFF)],
    'iterations': 5 } ],
    'expected': [('PORTD',0xBD)],
    },
    
    # Total Weight = 365, WeightDiff = 85, final binary should be 010110 11 or
    # 0x5B
    {
    'description': 'PINA: 0x8C, PINB: 0x00, PINC: 0xE1  => PORTD: 0x5B',
    'steps': [ {'inputs': [('PINA',0x8C), ('PINB',0x00), ('PINC',0xE1)],
    'iterations': 5 } ],
    'expected': [('PORTD',0x5B)],
    },

    # Total Weight = 100, WeightDiff = 100, final binary should be 000110 10 or
    # 0x1A
    {
    'description': 'PINA: 0x64, PINB: 0x00, PINC: 0x00  => PORTD: 0x1A',
    'steps': [ {'inputs': [('PINA',0x64), ('PINB',0x00), ('PINC',0x00)],
    'iterations': 5 } ],
    'expected': [('PORTD',0x1A)],
    },
    
    # Total Weight = 123, WeightDiff = 2, final binary should be 000111 00 or
    # 0x1C
    {
    'description': 'PINA: 0x3C, PINB: 0x03, PINC: 0x3A  => PORTD: 0x1C',
    'steps': [ {'inputs': [('PINA',0x3C), ('PINB',0x03), ('PINC',0x3A)],
    'iterations': 5 } ],
    'expected': [('PORTD',0x1C)],
    },

    ]
    
watch = ['main::tmpA', 'main::tmpB', 'main::tmpC', 'main::totalWeight', 'PORTD']

