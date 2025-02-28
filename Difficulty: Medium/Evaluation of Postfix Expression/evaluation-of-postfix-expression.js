//{ Driver Code Starts
const readline = require("readline")
                     .createInterface({input : process.stdin, output : process.stdout});

let t = null;
let inputs = [];
readline.on("line", line => {
    if (t === null) {
        t = parseInt(line);
    } else {
        inputs.push(line.trim());
        if (inputs.length === t) {
            readline.close();
        }
    }
});

readline.on("close", () => {
    const sol = new Solution();
    inputs.forEach(input => {
        const arr = input.split(" ");
        let result = sol.evaluate(arr);
        if (result === -0) result = 0;
        console.log(result);
        console.log("~");
    });
});

// } Driver Code Ends


class Solution {
    evaluate(arr) {
        const stack=[];
        
        for (let i=0;i<arr.length;i++){
            if (arr[i]==='+' || arr[i]==='-' || arr[i]==='*' || arr[i]==='/' ){
                const temp=BigInt(stack.pop());
                const temp1=BigInt(stack.pop());
                
                if (arr[i]==='+')
                stack.push(BigInt(temp+temp1));
                else if (arr[i]==='-')
                stack.push(BigInt(temp1-temp));
                else if (arr[i]==='*')
                stack.push(BigInt(temp*temp1));
                else if (arr[i]==='/')
                stack.push(BigInt(temp1/temp));
            } else{
                stack.push(BigInt(arr[i]));
            }
        }
        
        return parseInt(stack[0]);
    }
}
