
var join = function(arr1, arr2) {
    const map = new Map();

    // Add arr1 objects
    for (const obj of arr1) {
        map.set(obj.id, obj);
    }

    // Merge arr2 objects; arr2 properties override arr1
    for (const obj of arr2) {
        if (map.has(obj.id)) {
            map.set(obj.id, {
                ...map.get(obj.id),
                ...obj
            });
        } else {
            map.set(obj.id, obj);
        }
    }

    // Convert Map to array and sort by id
    return Array.from(map.values()).sort((a, b) => a.id - b.id);
};

