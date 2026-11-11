# Daily POTD — Contribution Guide

Use this checklist whenever adding a new GeeksforGeeks Problem of the Day.

## 1. Folder and file naming

Create one folder per problem:

`Daily-POTD/YYYY/Month/Day-DD-Problem-Name/`

Add these files:

- `README.md`
- `solution.cpp`

Use the actual POTD date (not the upload date) and a short, descriptive problem name.

## 2. README.md structure

Keep each problem write-up consistent:

1. Problem title and GeeksforGeeks link
2. POTD date, difficulty, and topic tags
3. Problem statement or a faithful summary
4. Examples and constraints
5. Understanding the problem
6. Approach and intuition
7. Algorithm / recurrence (when applicable)
8. Dry run with a clear table or walkthrough
9. Complete solution walkthrough
10. Time and auxiliary space complexity
11. Edge cases
12. Key DSA learnings
13. Interview-style explanation
14. Final takeaway

Write explanations in your own words. Link to the original problem rather than copying editorial text.

## 3. solution.cpp standards

- Use the function signature expected by GeeksforGeeks.
- Include only required headers (or `<bits/stdc++.h>` when appropriate).
- Keep code readable and interview-ready.
- Test boundary cases and constraints.
- Mention complexity in the README.

## 4. Before committing

- [ ] Problem link and POTD date are correct.
- [ ] Code matches the platform's required signature.
- [ ] Sample and edge cases have been considered.
- [ ] Dry run agrees with the implementation.
- [ ] Complexity analysis is accurate.
- [ ] Folder and file names follow the convention.
