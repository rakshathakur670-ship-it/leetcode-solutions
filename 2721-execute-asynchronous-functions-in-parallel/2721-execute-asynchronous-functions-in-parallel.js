
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const results = [];
        let completed = 0;

        functions.forEach((fn, index) => {
            fn()
                .then(value => {
                    results[index] = value;
                    completed++;

                    // Resolve only after every promise succeeds
                    if (completed === functions.length) {
                        resolve(results);
                    }
                })
                .catch(error => {
                    // First rejection rejects the returned promise
                    reject(error);
                });
        });
    });
};
