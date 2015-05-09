! A FORTRAN (95) subroutine that doubles all elements within
! a 'double precision' array 'data' of size 'sz'.
subroutine fortran_double(data, sz)

  ! FORTRAN is somewhat 'weird', at least relative to more modern languages,
  ! in that (optional!) type declarations are made _after_ the initial function
  ! name + argument list.
  integer sz
  double precision data(sz)

  ! The 'do' - 'end do' was, IIUC, introduced with Fortran 90. If you wanted
  ! this to work in way-too-old Fortran, you'd have to use labels and continues.
  ! *vomits profusely*
  do i = 1, sz
    data(i) = data(i) * 2
  end do

end
