 Prosthetic-Control-EMG-Gesture-Classification

This repository provides code and sample EMG data for decoding EMG signals to control a prosthetic arm. It also includes hardware, software, and experimental resources, offering a complete package for replication and further research.  

---

 Repository Contents

- **STL Files** – for 3D modeling  
- **3D Printing Settings** – recommended parameters for fabrication  
- **Arduino Scripts** – upload code for microcontroller integration  
- **Experimental Protocol Timeline** – used in each session to move between gestures  

---

Main Notebook

The primary modeling code is located in the `notebooks` directory:  
**`feature_extraction_pytorch_training_and_validation.ipynb`**  

This notebook can be divided into three main sections:

1. **Feature Generation**  
   - Handles EMG feature extraction.  

2. **Data Loading, Alignment, and Visualization**  
   - Loads EMG data and plots it alongside the experimental protocol timeline.  
   - Aligns gesture activity points with the protocol described in the paper.  
   - Compares alignment across sessions.  
   - Approximate protocol start times:  
     - *Subject 1*: Session 1 → 2.0s, Session 2 → 3.5s, Session 3 → 1.75s  
     - *Subject 2*: Session 1 → 8.55s, Session 2 → 8.3s, Session 3 → 3.4s  

3. **PyTorch Model Training and Validation**  
   - Two MLP implementations are provided:  
     - **6-Fold Stratified Cross-Validation (CV):** Splits data into 80% training / 20% testing. Works for both multi-subject and single-subject session data.  
     - **Cross-Session Evaluation (5-Fold Stratified CV):** Trains on the first two sessions, tests on the third. Includes an option to save predictions as a CSV for replay in prosthetic deployment.  

---

Cost Breakdown and Specifications

The cost breakdown and detailed part specifications are available in this Google Sheet:  
[Prosthetic Arm Parts List](https://docs.google.com/spreadsheets/d/1ARazL39SHxkO9HCzjxf5s1OOEaxhFiI-FpY4icmBl84/edit?usp=sharing)  

---
