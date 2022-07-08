import random

def selectionAlgorithm(candidates_skill_set, interviewing_cost, hiring_cost):
    BEST_CANDIDATE_SOFTWARE_ENGINEERING = {
        "Software Engineering" : -1,
        "Web Development" : -1,
        "App Development" : -11,
        "AIML" : -1,
    }
    BEST_CANDIDATE_WEB_DEVELOPMENT = {
        "Software Engineering" : -1,
        "Web Development" : -1,
        "App Development" : -1,
        "AIML" : -1,
    }
    BEST_CANDIDATE_APP_DEVELOPMENT = {
        "Software Engineering" : -1,
        "Web Development" : -1,
        "App Development" : -1,
        "AIML" : -1,
    }
    BEST_CANDIDATE_AIML = {
        "Software Engineering" : -1,
        "Web Development" : -1,
        "App Development" : -1,
        "AIML" : -1,
    }

    TOTAL_COST = 0
    for each in candidates_skill_set:
        TOTAL_COST += INTERVIEWING_COST
        if each["Software Engineering"] > BEST_CANDIDATE_SOFTWARE_ENGINEERING["Software Engineering"]:
            BEST_CANDIDATE_SOFTWARE_ENGINEERING = each
            TOTAL_COST += HIRING_COST
        elif each["Web Development"] > BEST_CANDIDATE_WEB_DEVELOPMENT["Web Development"]:
            BEST_CANDIDATE_WEB_DEVELOPMENT = each
            TOTAL_COST += HIRING_COST
        elif each["App Development"] > BEST_CANDIDATE_APP_DEVELOPMENT["App Development"]:
            BEST_CANDIDATE_APP_DEVELOPMENT = each
            TOTAL_COST += HIRING_COST
        elif each["AIML"] > BEST_CANDIDATE_AIML["AIML"]:
            BEST_CANDIDATE_AIML = each
            TOTAL_COST += HIRING_COST

    print(f'Candidate Chosen for Software Engineering : {BEST_CANDIDATE_SOFTWARE_ENGINEERING}\n\nCandidate Chosen for Web Development :{BEST_CANDIDATE_WEB_DEVELOPMENT}\n\nCandidate Chosen for App Development : {BEST_CANDIDATE_APP_DEVELOPMENT}\n\nCandidate Chosen for AIML : {BEST_CANDIDATE_AIML}\n\nTotal cost of filling all the positions: {TOTAL_COST}.')

run_iterations = 100000
print("Number of Applicants : ", run_iterations)
candidates_skill_set = []

for i in range(run_iterations):
    candidates_skill_set.append({
        "id" : i,
        "Software Engineering" : random.randint(1, 100000),
        "Web Development" : random.randint(1, 100000),
        "App Development" : random.randint(1, 100000),
        "AIML" : random.randint(1, 100000),
    })

print("Randomizing the candidate order...")
random.shuffle(candidates_skill_set)
INTERVIEWING_COST = 10
HIRING_COST = 50
print(candidates_skill_set[0])
selectionAlgorithm(candidates_skill_set, INTERVIEWING_COST, HIRING_COST)
