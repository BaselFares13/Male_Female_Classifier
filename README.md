# Gender Classification Based on Physical Attributes

This project implements a simple **Naive Bayes classifier** in C++ to predict whether a person is **male** or **female** based on:
- Height
- Weight
- Foot size

The program calculates probabilities using Gaussian (normal) distributions for each feature and classifies the input.

---

## 🚀 How it works

1️⃣ The program contains predefined data for males and females (height, weight, foot size).  
2️⃣ The user enters height, weight, and foot size at runtime.  
3️⃣ The program computes:
- Prior probabilities (`P(Male)`, `P(Female)`)
- Feature likelihoods (`P(Height|Gender)`, `P(Weight|Gender)`, `P(FootSize|Gender)`)
- Posterior probabilities using Bayes' theorem

4️⃣ The gender with the higher posterior probability is predicted.
