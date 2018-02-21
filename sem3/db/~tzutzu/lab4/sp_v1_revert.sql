create procedure sp_v1_revert
as
BEGIN
alter table Positions
alter column Nume varchar(50)
END