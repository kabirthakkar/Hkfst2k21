exports.randomSort = (arr) => {
    let n = arr.length;

    for (let i = 0; i < n; i++) {
        let j = Math.floor((i+1)*Math.random());
        let shuffledArr = arr;

        let tmp = shuffledArr[i];
        shuffledArr[i] = shuffledArr[j];
        shuffledArr[j] = tmp;        
    }

    return shuffledArr;
}
