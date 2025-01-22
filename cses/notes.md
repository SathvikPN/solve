random note dumps

---

Permutations and Combinations. ---------------------------------------------------------
as decision tree: <https://buildingvts.com/intuition-behind-permutations-and-combinations-db6ffa5272be>

k-slots & n-objects.

Number of ways to fill k-slots:-
if object can repeat: 
    n * n * n ... 
    n^k

if object cannot repeat:
    Consider different object positions in slot as count (nPk)
        n * (n-1) * (n-2) ... (n-k)
        n! / (n-k)!

    Donot consider different object positions in slot as count (nCk)
        nPk / k_ordering_count      (k_ordering_count = kPk)
        n! / (n-k)! / k!