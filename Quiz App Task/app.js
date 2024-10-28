const questions = [
  {
    question: "Who Are You ?",
    answers: [
      { text: "student", correct: true },
      { text: "Street Man", correct: false },
      { text: "Teacher", correct: false },
      { text: "Pian", correct: false },
    ],
  },
  {
    question: "Who Are You ?",
    answers: [
      { text: "student", correct: false },
      { text: "Street Man", correct: true },
      { text: "Teacher", correct: false },
      { text: "Pian", correct: false },
    ],
  },
  {
    question: "Who Are You ?",
    answers: [
      { text: "student", correct: false },
      { text: "Street Man", correct: false },
      { text: "Teacher", correct: true },
      { text: "Pian", correct: false },
    ],
  },
  {
    question: "Who Are You ?",
    answers: [
      { text: "student", correct: false },
      { text: "Street Man", correct: false },
      { text: "Teacher", correct: false },
      { text: "Pian", correct: true },
    ],
  },
];

const answerButtons = document.getElementById("answer-buttons");
const questionElement = document.getElementById("question");
const nextbtn = document.getElementById("nextbtn");


let currentQuestionIndex = 0;
let score = 0;

function startQuiz(){
    currentQuestionIndex = 0;
    score = 0
    nextbtn.innerHTML="Next"
    showQuestion()
}

function showQuestion(){
    resetState()
    let currentQuestion = questions[currentQuestionIndex]
    let questionNo = currentQuestionIndex +1
    questionElement.innerHTML = questionNo + ". " + currentQuestion.question
    currentQuestion.answers.forEach(answer =>{
        const button = document.createElement("button");
        button.innerHTML = answer.text
        button.classList.add("btn")
        answerButtons.appendChild(button)
        if(answer.correct){
          button.dataset.correct = answer.correct
        }
        button.addEventListener("click", selectAnswer)
    })

}


function resetState(){
    nextbtn.style.display = "none"
    while(answerButtons.firstChild){
        answerButtons.removeChild(answerButtons.firstChild)
    }
}

function selectAnswer(e){
  const selectBtn = e.target
  const isCorrect = selectedBtn.dataset.correct === "true"
  if(isCorrect){
    selectBtn.classList.add("correct")
  }else{
    selectBtn.classList.add("incorrect")
  }
}
startQuiz()

