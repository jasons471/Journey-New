class question:
    def __init__(self, prompt, answer):
        self.prompt = prompt
        self.answer = answer
        
question_prompts = [
    "What is the capital of France?\n(a) Madrid\n(b) Paris\n(c) Rome\n\n",
    "What is the capital of Spain?\n(a) Madrid\n(b) Paris\n(c) Rome\n\n",
    "What is the capital of Italy?\n(a) Madrid\n(b) Paris\n(c) Rome\n\n"
]
questions = [
    question(question_prompts[0], "b"),
    question(question_prompts[1], "a"),
    question(question_prompts[2], "c")
]

def run_test(questions):
    score = 0
    for question in questions:
        answer = input(question.prompt)
        if answer == question.answer:
            score += 1
    print("You got " + str(score) + "/" + str(len(questions)) + " correct")
run_test(questions)