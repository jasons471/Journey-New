const users = [
  { id: 101, name: " Ada ", scores: [10, 20, 30] },
  { id: 102, name: "", scores: [5, 0, 15] },
  { id: 103, name: null, scores: [7, 14] },
  { id: 104, scores: [3, 3, 3, 3] },
  { id: 105, name: "Grace", scores: [] }
];

function normalizeName(value){
    if (value === null || value === undefined || value.trim() === "") {
        return "Unknown";
    }
    else {
        return value.trim();
    }
}
function averageScores(scores) {
    if(!Array.isArray(scores)){
        //Array is a built-in object in JavaScript that allows you to store multiple values in a single variable. 
        /*something.issomething() is a method that checks 
        if the something is of a certain type. 
        In this case, it checks if scores is an array.*/
        return null;
    }
    else if (scores.length === 0) {
        return null;
    }
    else{
        const total= scores.reduce((acc, score) => acc + score, 0) / scores.length;
       // . is used to access the length property of the scores array, 
        /*=> is an arrow function that takes 
        two parameters, acc and score,
        and returns the sum of acc and score.*/
        const avg = total / scores.length;
        return Math.round(avg * 100) / 100; // Round to two decimal places
    }
       const avg = total / scores.length;
        return Math.round(avg * 100) / 100; // Round to two decimal places
    }
    function buildUserSummary(user) {
        if(typeof user !== "object" || user === null){
            throw new Error("User must be an object.");
        }
        const id = user.id;
        //id is a property of the user object that holds the user's id.
        const name = normalizeName(user.name);
       //name is a property of the user object that holds the user's name.
        const scores = user["scores"];
        //scores is a property of the user object that holds the user's scores.
       const isscorearray = Array.isArray(scores);
       const scoreCount = isscorearray ? scores.length : 0;
       //scoreCount is a variable that holds the number of scores the user has.
       /*? is a ternary operator that checks if isscorearray is true.
         If it is true, it returns scores.length,
         If it is false, it returns 0.*/
         // : this represents the else part of the ternary operator.
  const avg = isscorearray && scores.length > 0 ? averageScore(scores) : null;
  /*alternate way of writing if else statement, 
  if isscorearray is true and scores.length is greater than 0, it returns averageScore(scores),
   otherwise it returns null.*/
 return {id, name, scoreCount, avg};
    }
    function SummarizeUsers(userArray) {
       if(!Array.isArray(userArray)){
        throw new Error("UserArray must be an array.");
       }
       return userArray.map(buildUserSummary);
       /*map() is a built-in method in JavaScript 
       that creates a new array by calling a provided function on every element in the calling array.*/
    }
 function safeSummarizeUsers(userArray) {}
    
    
    
    
    
   





