create procedure sp_v5_upgrade
as
BEGIN
alter table Version4
add constraint FK_Constraint
foreign key (ID) references Filler(id)
END