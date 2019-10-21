#### 1.reset file
```Bash
pwd
##cd 到要reset file的路径下
git reset 'hash-code' ./filename
git checkout -- ./filename
```
#### 2.git checkout error
```
Unlink of file '......' failed. Should I try again?
```
出现这种情况，基本上可以说是文件被占用了，git的LFS是无法


#### 3.reset folader
```Bash
pwd
##cd 到要reset folder的parent路径
git reset 'hash-code' ./folder
git checkout -- ./folder
```
如果出现"fatal: Cannot do hard reset with paths."的错误，没有指定路径，或者路径指定错误
#### 4.push 单个文件或者文件夹
```Bash
pwd
##cd 到包含这些文件的总文件夹，但是之后参数要带上相对路径
git add foladers/filenames
git commit -m "msg" foladers/filenames
git push origin master
```

#### 5.删除某个commit
找到一个[参考](https://www.clock.co.uk/insight/deleting-a-git-commit)，觉得靠谱，之后试一试
>Using Cherry Pick
>Step 1: Find the commit before the commit you want to remove git log
>
>Step 2: Checkout that commit git checkout <commit hash>
>
>Step 3: Make a new branch using your current checkout commit git checkout -b <new >branch>
>
>Step 4: Now you need to add the commit after the removed commit git cherry-pick ><commit hash>
>
>Step 5: Now repeat Step 4 for all other commits you want to keep.
>
>Step 6: Once all commits have been added to your new branch and have been commited. >Check that everything is in the correct state and working as intended. Double check >everything has been commited: git status
>
>Step 7: Switch to your broken branch git checkout <broken branch>
>
>Step 8: Now perform a hard reset on the broken branch to the commit prior to the one >your want to remove git reset --hard <commit hash>
>
>Step 9: Merge your fixed branch into this branch git merge <branch name>
>
>Step 10: Push the merged changes back to origin. WARNING: This will overwrite the >remote repo! git push --force origin <branch name>
>
>You can do the process without creating a new branch by replacing Step 2 & 3 with >Step 8 then not carry out Step 7 & 9.