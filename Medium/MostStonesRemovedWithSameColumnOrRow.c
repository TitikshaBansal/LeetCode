void dfs(int** stones, int stonesSize, bool* visited, int index) {
    visited[index] = true;
    for (int i = 0; i < stonesSize; ++i) {
        if (!visited[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])) {
            dfs(stones, stonesSize, visited, i);
        }
    }
}

int removeStones(int** stones, int stonesSize, int* stonesColSize) {
    bool* visited = (bool*)malloc(stonesSize * sizeof(bool));
    for (int i = 0; i < stonesSize; ++i) {
        visited[i] = false;
    }

    int maxMoves = 0;
    for (int i = 0; i < stonesSize; ++i) {
        if (!visited[i]) {
            dfs(stones, stonesSize, visited, i);
            maxMoves += 1;
        }
    }

    free(visited);
    return stonesSize - maxMoves;
}
