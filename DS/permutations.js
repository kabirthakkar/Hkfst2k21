
  
function permutations(arrayValue) {
  const array = [...arrayValue];
  if (array.length <= 1) return yield array;
  for (const [item, index] of enumerate(array)) {
    const withoutCurrent = array.filter((_, i) => i !== index);
    for (const permutation of permutations(withoutCurrent)) {
      yield [item, ...permutation];
    }
  }
}

function enumerate(arrayValue) {
  let index = 0;
  for (const item of iterable) {
    yield [item, index];
    index++;
  }
}

module.exports = permutations
