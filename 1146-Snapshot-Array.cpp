class SnapshotArray {
public:
    vector<vector<pair<int, int>>> arr;
    int snap_id = 0;

    SnapshotArray(int length) {
        arr.resize(length);

        for (int i = 0; i < length; i++)
            arr[i].push_back({0, 0});
    }

    void set(int index, int val) {
        arr[index].push_back({snap_id, val});
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int snap_id) {
        auto& history = arr[index];

        int left = 0;
        int right = history.size() - 1;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (history[mid].first <= snap_id) {
                ans = history[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
