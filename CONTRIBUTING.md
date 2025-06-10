push # Contribution Guidelines

This guide walks you through how to contribute your weekly competitive programming solutions to this repository using a fork-based workflow.

---

## Steps to Contribute

### 1. Fork This Repository

- Visit: [https://github.com/sanchitachaurasia/SOC_CP](https://github.com/sanchitachaurasia/SOC_CP)
- Click on the top-right **"Fork"** button.
- This creates a personal copy of the repo under your GitHub account.

---

### 2. Clone Your Fork Locally

Open terminal and run:

```bash
git clone https://github.com/<your-username>/SOC_CP.git
cd SOC_CP
````

---

### 3. Create a Branch With Your Full Name

This is where you’ll keep your weekly solutions.

```bash
git checkout -b your-name
```

✅ Example:

```bash
git checkout -b sanchita-chaurasia
```

---

### 4. Add Your Weekly Solutions

* Organize your files under folders like:

  ```
  /week_1/
  /week_2/
  /week_3/
  ```
 This will be done by us already, as we have a separate README.md inside each folder containing the questions to be completed for that specific week.
 
* Name your files. Example:

  ```
  week_1/sort_colors.cpp
  week_1/kth_largest_element.py
  ```
  or
  ```
  week_1/lc_1.cpp
  week_1/cses_1.py
  ```
  You may use any kind of naming convention.

---

### 5. Commit and Push Your Code

```bash
git add .
git commit -m "Add Week 1 solutions"
git push origin your-name
```

---

### 6. Create a Pull Request (PR)

* Do this once you have finished the work for that specific week.
* Go to your forked repo on GitHub.
* Click **"Compare & pull request"**.
* Set:

  * **Base repository:** `sanchitachaurasia/SOC_CP`
  * **Base branch:** `<your-name>` (⚠️ not `main`)
  * **Head repository:** your fork
  * **Head branch:** `<your-name>`
* Click **Create Pull Request**.

---

### 7. Repeat Every Week

* Add your new solutions to the same branch.
* Push changes.
* Your PR will automatically update.
     
---

## ❗ Rules & Best Practices

* Do **not** push directly to `main`.
* Submit PRs only to your **own named branch**.
* Ask doubts and share progress in the WhatsApp group.
* Write clean and readable code — include comments if necessary.
* Organize your code by week and problem.

---
