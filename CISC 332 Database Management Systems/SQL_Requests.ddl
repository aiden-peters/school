
select fname, lname, ssn
from employee
where salary in (select min(salary) from employee);

select fname, lname
from employee, dependent
where ssn = essn and relationship="spouse" and
ssn in (select essn from dependent where relationship = "daughter");

select fname, lname, pname
from works_on inner join Employee
on ssn = essn
inner join Project
on pnumber =pno
where (lname = "Wong" or lname = "Borg" or lname = "English");

select fname, lname, ssn, salary
from department, employee
where mgrssn=ssn
and salary>30000 and sex='M';

select pname, PNo
from project, works_on, employee
where ssn=essn and pno = pnumber
and lname = "Narayan" and pno IN
(select pno from works_on, employee
where essn = ssn and lname = "Jabbar");

select fname, lname, Year(CURRENT_DATE) - Year(Dependent.Bdate) as Age
from employee, dependent
where ssn=essn and year(dependent.bdate) > 1970;
select * from dependent;

create view WorksOnHoustonProjects as
select essn
from works_on
where pno in (select pnumber from project where plocation = 'Houston')
group by essn
having count(*) = (select count(pnumber) from project where plocation = 'Houston');
select fname, lname, pname, sum(hours) as TotalHours
from employee E, WorksOnHoustonProjects H, works_on W, Project P
where E.ssn = H.essn and H.essn = W.essn and W.pno = P.PNumber and P.plocation = 'Houston'
group by E.ssn;

select E1.fname, E1.lname, E2.fname as supervisorFname, E2.lname as supervisorLname
from Employee E1 left join Employee E2
on E1.superssn = E2.ssn;

select pname, fname, lname, plocation
from project, department, employee
where dnum=dnumber and mgrssn = ssn;

select fname, lname
from department, employee
where mgrssn=ssn
and salary in (select max(salary) from employee, department where mgrssn = ssn);

