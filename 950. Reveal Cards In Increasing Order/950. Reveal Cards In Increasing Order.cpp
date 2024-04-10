class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        // Reverse sort the deck so that we get the largest card first
        sort(deck.rbegin(), deck.rend());

        // Init a double-ended queue to simulate the process
        deque<int> queue;

        // Iterate over the sorted deck
        for (int card : deck) {

            // If the queue isn't empty, simulate the 'revealing' process:
            // move the last element to the front to mimic the card placement in the final deck
            if (!queue.empty()) {
                queue.push_front(queue.back());
                queue.pop_back();
            }

            // Place the current largest card in the front
            queue.push_front(card);
        }

        // Convert the deque back to a vector and return it
        return vector<int>(queue.begin(), queue.end());
    }
};