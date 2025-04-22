exp 8 :
-- Step 1: Create and use database
CREATE DATABASE se2;
USE se2;

-- Step 2: Create table
CREATE TABLE emp (
    Employee1D INT PRIMARY KEY AUTO_INCREMENT,
    EmployeeName VARCHAR(100) NOT NULL,
    Department1D INT NOT NULL,
    Salary INT NOT NULL
);

-- Step 3: Insert data
INSERT INTO emp (EmployeeName, Department1D, Salary) VALUES
('Alice', 1, 500),
('Bob', 2, 600),
('Charlie', 1, 550),
('David', 3, 700),
('Ema', 2, 620);

-- Step 4: (Optional) Create stored procedure to fetch all employees by department
DELIMITER //
CREATE PROCEDURE getallempbydept(IN deptid INT)
BEGIN
    SELECT * FROM emp WHERE Department1D = deptid;
END;
//
DELIMITER ;

-- Example call to procedure
CALL getallempbydept(2);

-- Step 5: Create function to get total salary by department
DELIMITER //
CREATE FUNCTION getsalbydept(deptid INT) RETURNS DECIMAL(10,2)
DETERMINISTIC
BEGIN
    DECLARE totalsal DECIMAL(10,2);
    SELECT SUM(Salary) INTO totalsal
    FROM emp
    WHERE Department1D = deptid;
    RETURN totalsal;
END;
//
DELIMITER ;

-- Step 6: Call the function
SELECT getsalbydept(2) AS totalsalary;







exp9:

create database student;
use student;
CREATE TABLE student (
  sid INT PRIMARY KEY,
  sname VARCHAR(20),
  marks INT
);

-- Insert some data
INSERT INTO student VALUES
(1, 'Aditi', 85),
(2, 'Karan', 90);

-- Create a simple view showing names and marks
CREATE VIEW student_view AS
SELECT sname, marks FROM student;

-- To use the view
SELECT * FROM student_view;





-- Create a log table for updates
CREATE TABLE student_log (
  log_id INT AUTO_INCREMENT PRIMARY KEY,
  sname VARCHAR(20),
  action VARCHAR(20),
  log_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Create a trigger that logs updates
DELIMITER //
CREATE TRIGGER log_update
AFTER UPDATE ON student
FOR EACH ROW
BEGIN
  INSERT INTO student_log (sname, action)
  VALUES (OLD.sname, 'Updated');
END;
//
DELIMITER ;

-- Example update that activates the trigger
UPDATE student SET marks = 95 WHERE sid = 1;

-- Check the log
SELECT * FROM student_log;





