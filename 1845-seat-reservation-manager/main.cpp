class SeatManager {
public:
    // this set will be a sorted list of all 
    // the unreserved seats;
    // we will check if the first freed set is lower than boundary
    set<int> freed;
    
    // from [boundary, boundary + 1, boundary + 2, ..., max_seat]
    // the seats have not been reserved
    int boundary = 0;
    int max_seat = 0;

    int lowest_unreserved = 0;

    SeatManager(int n) {
        lowest_unreserved = 1;
        boundary = 1;
        max_seat = n;
    }
    
    // this function finds the smallest
    // unreserved seat from either
    // the "freed" sorted set or from 
    // the [boundary, ..., max_seat] range
    int reserve() {
        if (!freed.empty()) {
            auto first = freed.begin();
            int val = *first;

            if ((*first) < boundary) {
                lowest_unreserved = *first;
                freed.erase(first);
                return lowest_unreserved;
            }
        }
        
        lowest_unreserved = boundary;
        boundary++;

        return lowest_unreserved;
    }
    
    void unreserve(int seat_number) {
        if (seat_number == boundary - 1) {
            boundary--;
        } else {
            freed.insert(seat_number);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */