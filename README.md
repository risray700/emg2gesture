# Prosthetic-Control-EMG-Gesture-Classification
This repository provides code and some sample EMG data for decoding EMG signals to control a prosthetic arm. It also includes other details  offering a complete resource for replication and further research,
    - STL files for 3D modeling
    - Settings used for 3D printing
    - Scripts used to upload code to Arduino
    - The experimental protocol timeline used within every session to move between gestures,

The main modeling code resides in the notebooks directory, specifically the notebook **feature_extraction_pytorch_training_and_validation.ipynb** takes care of feature generation, model training as well as validation. It can be divided broadly into three sections,
    1. *Feature Generation*: The first section handles feature generation.
    2. *Data Loading, Alignment and Visualization*: The second section loads the EMG data and plots it alongside the experimental protocol timeline, showing the alignment of gesture activity points with the protocol described in the paper. It also compares alignment across different sessions for each subject.A list of three values is provided, representing the approximate time points where each recording session began:
        - Subject 1: Session 1 → 2.0s, Session 2 → 3.5s, Session 3 → 1.75s
        - Subject 2: Session 1 → 8.55s, Session 2 → 8.3s, Session 3 → 3.4s
    3. *PyTorch Model Training and Validation*: At the bottom of the code are two MLP implementations:
        - **6-Fold Stratified Cross-Validation (CV)**: Randomly splits all loaded sessions into 80% training and 20% testing. For example, if three sessions are loaded for both subjects, the dataset is split randomly into 80%/20%. If only one subject’s three sessions are loaded, the same 80%/20% random split applies.
        - **Cross-Session Evaluation (5-Fold Stratified CV)**: Trains on the first two sessions and tests on the third. This code also includes an option to save the predicted results as a CSV file, which can be used by the prosthetic deployment code to replay the predicted session.

The cost breakdown and specs are detailed in this document,
This is the link to the parts list for the Prosthetic Arm:https://docs.google.com/spreadsheets/d/1ARazL39SHxkO9HCzjxf5s1OOEaxhFiI-FpY4icmBl84/edit?usp=sharing




