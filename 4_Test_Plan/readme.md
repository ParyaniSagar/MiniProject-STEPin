# TEST PLAN:

| **Test ID** | **Description**                                   | **Exp OUT** | **Actual Out** | **Type Of Test**  |
|-------------|---------------------------------------------------|-------------|----------------|-------------------|
| T_01        | File IO - Try to read a wrong file                | NO_FILE     | NO_FILE        | Scenario based    |
| T_02        | File IO - Try to pass an invalid pointed          | NULL_PTR    | NULL_PTR       | Scenario based    |
| T_03        | File IO - reading correct file with valid pointer | SUCCESS     | SUCCESS        | Scenario based    |
| T_04        | Entering wrong question pointer in the game       | NULL_PTR    | SUCCESS        | Requirement based |
