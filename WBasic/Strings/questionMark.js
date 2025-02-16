function QuestionsMarks(str) {
  let flag = false;
  let question = 0;
  let sum = 0;
  let ans = false;

  for (let i = 0; i < str.length; i++) {
    if (!isNaN(str[i])) {
      flag = !flag;
      if (flag) {
        sum = Number(str[i]);
        question = 0;
      } else {
        sum = sum + Number(str[i]);
        if (sum == 10) {
          if (question == 3) ans = true;
          else return "false";
          question = 0;
          sum = Number(str[i]);
          flag = true;
        }
      }
    } else if (str[i] == "?" && flag) {
      question++;
    }
  }
  // code goes here
  return ans ? "true" : "false";
}

// keep this function call here
console.log(QuestionsMarks(readline()));
